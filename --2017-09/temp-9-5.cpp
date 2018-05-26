#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>> res;
		unordered_map<string, int> dict;
		for (int i = 0; i < words.size(); ++i) {
			string key = words[i];
			reverse(key.begin(), key.end());
			dict[key] = i;
		}

		if (dict.find("") != dict.end()) {
			for (int i = 0; i < words.size(); ++i) {
				if (i == dict[""]) continue;
				if (helper(words[i])) res.push_back({ dict[""], i });
			}
		}
		for (int i = 0; i < words.size(); ++i)
			for (int j = 0; j < words[i].size(); ++j) {
				string left = words[i].substr(0, j);
				string right = words[i].substr(j);

				if (dict.find(left) != dict.end() && helper(right) && dict[left] != i) {
					res.push_back({i, dict[left]});
				}
				if (dict.find(right) != dict.end() && helper(left) && dict[right] != i) {
					res.push_back({dict[right], i});
				}
			}
		return res;
	}

	vector<int> findErrorNums(vector<int>& nums) {
		vector<int> res(2, 0);
		int temp = 0;
		for (int i = 0; i < nums.size(); ++i) {
			int val = abs(nums[i]);
			temp = temp ^ (i + 1) ^ val;
			if (nums[val - 1] < 0) res[0] = val;
			else nums[val - 1] *= -1;
		}
		res[1] = temp ^ res[0];
		return res;
	}

	int totalHammingDistance(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < 32; ++i) {
			int temp = 0;
			for (int j = 0; j < nums.size(); ++j)
				temp += (nums[j] >> i) & 1;
			res += temp * (nums.size() - temp);
		}
		return res;
	}

	int minDistance(string word1, string word2) {
		//int m = word1.length(), n = word2.length();
		//vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		//for (int i = 1; i <= m; ++i)
		//	dp[i][0] = i;
		//for (int i = 1; i <= n; ++i)
		//	dp[0][i] = i;
		//for (int i = 1; i <= m; ++i)
		//	for (int j = 1; j <= n; ++j) {
		//		if (word1[i - 1] == word2[j - 1])
		//			dp[i][j] = dp[i - 1][j - 1];
		//		else
		//			dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1));
		//	}
		//return dp[m][n];

		// O(n)
		int m = word1.length(), n = word2.length();
		vector<int> cur(m + 1, 0);
		for (int i = 1; i <= m; ++i)
			cur[i] = i;
		for (int j = 1; j <= n; ++j) {
			int pre = cur[0];
			cur[0] = j;
			for (int i = 1; i <= m; ++i) {
				int temp = cur[i];
				if (word1[i - 1] == word2[j - 1])
					cur[i] = pre;
				else
					cur[i] = min(pre + 1, min(cur[i] + 1, cur[i - 1] + 1));
				pre = temp;
			}
		}
		return cur[m];
	}


	int findDuplicate(vector<int>& nums) {
		//int len = nums.size();
		//for (int i = 0; i < len; ++i) {
		//	int val = abs(nums[i]);
		//	if (nums[val] < 0) return val;
		//	else nums[val] = -nums[val];
		//}

		// O(log n)
		//int low = 1, hig = nums.size() - 1;
		//while (low < hig) {
		//	int count = 0;
		//	int mid = (low + hig) / 2;
		//	for (auto num : nums)
		//		if (num <= mid)
		//			count++;
		//	if (count <= mid) low = mid + 1;
		//	else hig = mid;
		//}
		//return low;

		// O(n)
		int slow = nums.size();
		int fast = nums.size();
		do {
			slow = nums[slow - 1];
			fast = nums[nums[fast - 1] - 1];
		} while (slow != fast);
		slow = nums.size();
		while (slow != fast) {
			slow = nums[slow - 1];
			fast = nums[fast - 1];
		}
		return slow;

	}

	int maximalSquare(vector<vector<char>>& matrix) {
		//int m = matrix.size();
		//if (m == 0) return 0;
		//int n = matrix[0].size();
		//int squ = 0;
		//vector<vector<int>> dp(m, vector<int>(n, 0));
		//for (int i = 0; i < m; ++i) {
		//	dp[i][0] = matrix[i][0] - '0';
		//	squ = max(squ, dp[i][0]);
		//}
		//for (int i = 0; i < n; ++i) {
		//	dp[0][i] = matrix[0][i] - '0';
		//	squ = max(squ, dp[0][i]);
		//}
		//for (int i = 1; i < m; ++i)
		//	for (int j = 1; j < n; ++j) {
		//		if (matrix[i][j] == '0')
		//			dp[i][j] = 0;
		//		else
		//			dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
		//		squ = max(squ, dp[i][j]);
		//	}
		//return squ*squ;

		// Optimal Solution
		if (matrix.empty()) return 0;
		int m = matrix.size(), n = matrix[0].size();
		vector<int> dp(n+1, 0);
		int maxsize = 0, pre = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 1; j <= n; ++j) {
				int temp = dp[j];
				if (matrix[i][j-1] == '1') {
					dp[j] = min(pre, min(dp[j - 1], dp[j])) + 1;
					maxsize = max(maxsize, dp[j]);
				}
				else dp[j] = 0;
				pre = temp;
			}
		}
		return maxsize * maxsize;

		// Author's Solution
		/*if (matrix.empty()) return 0;
		int m = matrix.size(), n = matrix[0].size();
		vector<int> dp(m + 1, 0);
		int maxsize = 0, pre = 0;
		for (int j = 0; j < n; ++j) {
			for (int i = 1; i <= m; ++i) {
				int temp = dp[i];
				if (matrix[i - 1][j] == '1') {
					dp[i] = min(dp[i], min(dp[i - 1], pre)) + 1;
					maxsize = max(maxsize, dp[i]);
				}
				else dp[i] = 0;
				pre = temp;
			}
		}
		return maxsize * maxsize;*/
	}
	 
	int lengthOfLIS(vector<int>& nums) {
		//if (nums.empty()) return 0;
		//int len = nums.size();
		//vector<int> dp(len, 1);
		//int maxlen = 1;
		//for (int i = 1; i < len; ++i) {
		//	int temp = 0;
		//	for (int j = 0; j < i; ++j) {
		//		if (nums[j] < nums[i])
		//			temp = max(temp, dp[j]);
		//	}
		//	dp[i] = temp + 1;
		//	maxlen = max(dp[i], maxlen);
		//}
		//return maxlen;

		vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			auto it = lower_bound(res.begin(), res.end(), nums[i]);
			if (it == res.end()) res.push_back(nums[i]);
			else *it = nums[i];
		}
		return res.size();

	}

private:
	bool helper(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			if (s[i] != s[j])
				return false;
			++i;
			--j;
		}
		return true;
	}


};


// *************************** ·Ö¸îÏß ***************************
int main() {
	Solution A = Solution();

	vector<int> nums{  2, 1, 3};
	cout << A.lengthOfLIS(nums) << endl;



	//vector<vector<char>> matrix{
	//	{'1', '0', '1', '0', '0'},
	//	{'1', '0', '1', '1', '1'},
	//	{'1', '1', '1', '1', '1'},
	//	{'1', '0', '0', '1', '0'}
	//};
	//cout << A.maximalSquare(matrix) << endl;

	//vector<int> nums{ 1,1,2,3 };
	//cout << A.findDuplicate(nums) << endl;

	//vector<int> nums{ 1,2,3,4,5,5 };
	//vector<int> res = A.findErrorNums(nums);
	//cout << res[0] << " " << res[1] << endl;

	//vector<string> words{ "abcd", "dcba", "lls", "s", "sssll" };
	//vector<string> words1{ "bgcahbciadagghie","cajgfcbegieehcd","jfacifeejiijaccae","jbcicdiebddejceeb","hje","ciaafiabgcjjd","abcfecacgbjejieghd","eeeaeej","gegagdabegbeffhabdi","ejb","fbbdfffbbgdafagegd","ecbgdfdabbfehcdfbcj","acaddeaidebiedddd","gh","eefigccahg","jgcehbbbhccee","bacbhaaffbadhcej","ieaehbeajbibig","caaaj","jf","higidc","dbjjfcdge","bbgcjeiaig","eaehbehfcgeacfajdj","ibgeih","bfgg","fcbhe","ajcfefhafgbdicdaddhe","jjh","cgd","agjjafci","jjdcfgigcjhabgbe","aihebchihaj","ajg","bcbfjdhggiejiegb","dcidcjfjbjdeaaaa","adjfafdiidhbd","agcgc","ibadbjaibbfedeihc","f","dfhbfc","cafcabf","jagabhccb","gihjgdghheecccjh","dcgagidcc","eagbacfbhhdfhbdee","ciabd","bffhffji","afhdacaieggchbe","dijccbdahfabdc","ffeggc","aghgadjjgj","bjadiibjedid","bgcghaheei","icaiaehegbj","ghjadjihcfded","ej","gfgdhiajhd","ede","ggg","hjjdehhja","bagif","fcfdgfcfbjjfeffia","c","bdcejcacbghgahcafe","ejhbfijefb","dfhjhegeafjcigbbia","fgdffacbejajic","chcfgfgjcbiehicfd","ejahbjbcbicjagachj","a","egbgfibdahjadafcgd","gjfbjjbaidhiehafegfd","hfaaeiceefbhcgea","bhhfdf","gbdfjjaccdfcbhhhehf","ejeeeaac","abajajb","ehdcijage","fbigaeifehc","bdghgdi","jhafgbjfieaijgbej","fehehbgabdhhgadhadbg","jaighehajjhcecbjc","adjdbidf","jbfahhihjg","hbbgdi","gcjcggfhdihfb","heigdhji","ahabiaeie","hhedjbaha","bfhjjhbb","ijhdfiafhhehjghgfi","dcgedjgaeffhajhag","g","jhjceaaaifafdggfjbg","ghbdcbjhgeeehhcbf","ffgfceejhec","ifabh","hhihcfbbhe","cdhdgjgcdd","cchcebbggjjffiihdccg","iifbgh","ff","jjehcheh","bciehbbcjgjb","h","hehgfiiejecfjiheedi","aijij","bifghcabigi","gejfccgdfibehjjb","gcjjbffgiag","cadagdeh","hhhgfeddfdfh","dffihfiabfadgeiiedfd","cheeieejejeibe","ceijced","dhbfhhfha","iicacg","eadcjfcfjgdeegihb","cfadjcagje","gi","eiafffehbicih","babdjgc","didhdifig","jfhcdig","cddhh","ffihbbb","ajfeacghfbghgjhbgf","bcbgaejjgih","jhbgbi","cichadjabgec","gahfjibcbijehejbeja","ffac","aajdaafabeicbgggch","fcgcajcfhfjhbhhbdja","fbaieaggbdfhcbgg","iggaec","afd","dgbiejffcihhhh","ddaihgadjajhgecghb","gfdcije","gjeeaibgdeeiiehfag","afhhdjciadbhfijia","dbjd","hgcahhh","cadjbjibjjgfecedd","hhedh","d","bbhccjahdjhde","cghecigajdfcebaj","hbefgj","ijdchhbg","jgfcdfbgjbjaadeji","jibedfieeeaddfcc","geaggid","heicfjja","dhffajiibegj","bebjbfijhggef","jgfffhe","iciehbgcdaj","bhgdjfchhfbhcc","hbdfhffjibjiejeehdia","fcfhihdjefbif","ddfhejhcaecigbicjcfb","cgdaj","iejeiccd","gcdgibedjagiajgccjj","cf","ddgeeajaiafaaah","eafjajgaj","fiidfdgdfegdejfch","hcadjhaeddgegheachae","jffjhjhhbdciid","ijhhfgjafafgc","feejjjjicfiej","gifbfhjedibgc","heihahagfbgi","ha","gafjiebffdjeda","di","debbffaafhejbiegbbgb","ibiai","aibacbhadedihjghia","hdjeeijejbjdbhjje","jiabhdafhbhgcfcgbgcc","dgibabc","fjhcbejhddid","fgbaa","bdbecijb","gdjigbhf","gdacf","ijgaggafgciibgegeab","dgbij","ieaihec","bicfcbijd","dfcjbchda","badhh","fbacffdeejeeieidci","hf","afajihhdbjfaehgbiic","jhj","ieadbjbajhf","aaggiaggbd","ajiihgid","jacceifhihafcejbgdfj","agg","bchebejff","ffafgifbjaifcdcjac","bfhcdac","ciaccdgaaddhdddggajc","ficbgicjdigdb","j","iiaccjfdgheada","ahhiaabhjjgcfiffh","dafgcbhddecbcaificb","igiegagid","fcicgbecchfcbfh","hd","ecd","eibgdahagj","fagb","gaia","fhfhedcideejfh","fcjfdhfdhjcb","i","gfahba","bhbfeh","iicfddifedf","hajdh","ibjabeebabjeebadid","gcade","fcgiebibcee","fidbcfcbj","jjbefffgb","jdhicajehjjieaffah","hieacaehedcfjhd","ajbhehbbedabgd","dgaaffaaddcac","hcihiddcacigbihdde","fgfbbgjcfccdigiifg","fbbgcafhjchgege","fehdebe","cjbef","edeech","iacfgjgb","bfhbfajbgjghghefjfe","ajcab","hahadbhgaaijihdg","bbbfj","acddcaaa","jjffjg","daffibbgbgd","gif","adfajecefibjgfijia","ecfjdhbg","icjgghdggaccjfca","cbijbdda","ebcgefg","hhdihbdech","giecihcfheigadacccej","dfdihbdecicih","acgfjahdggaedj","idbfcbjheaeejbhgh","eg","fccccacfj","bdeejfgjegedjfi","eeecjchfd","fgcbacjajgjhcicedhb","ggihffdhcjdhceihefeb","hb","fejcdgjecgbgad","efedbfefdjcdbdbf","idggadbhcgc","eecgbggicdfgdchdc","jfebg","eiajhcjgcgcbiijcdbd","ddbabbdiejea","afijhecebeaicjdbh","egfggicgafdfjffchc","ibe","ebgafcabicdadfcf","gccgdd","df","bh","fjhcfidjcfjjf","dgabf","iegdi","hhajdhhfbcb","hifiagahhjdajaffg","diaieigfbjbi","igadhdccbagdbdhb","afbebcg","hdbabgcb","bajhfcaffd","hihajh","ihddehfdbbfdhijajj","ddhhebifhdbhehi","agchhgf","dfddhfb","iecdi","fbdaeicec","gacbfijideifjeci","igefbebaajjb","ae","efj","gd","ehighddgheigbba","cdgjhdhhhig","fbeaj","icjdcchd","decbbeiace","dbgeaebcdifcgje","fecahfbjge","gecaibhgefchabhjba","cfbhe","ijhhabghjhaihgchhijh","eaebiaa","djjdjcjjbijece","aeajjcdiecajci","hhgcgidjedhceee","jjihccjicggedefdja","ggfedgfc","gbecdg","fagjaiicgaeaajdbic","eciifeejadicdfif","edfcjffaj","cjjabfddiaeeccch","fdcfeffgjj","ffdgfg","fbccfcgi","acjjb","efjijdhfdbh","hajiccffdcjibcdb","bgfdag","bajaggbbhjb","bfaijdfgiibfd","ggdc","cebeajibb","hfajea","e","gegjfge","ffhcf","chbcfejidifffcfhdafd","ffdhjagage","bccj","aggf","caddgheabfiebg","jaefdiajfgg","ghjacdjgbieddcc","aifhhdbbfbhebcdhgeab","fci","figfjibfefgdhjfgd","efibdccbicafggd","b","ddicbcaaijehcjfg","hdffieaaaijbbcigfhfe","ajead","dhhif","ajbf","jgcja","jibgajaiecfhhbgdceg","ccibagddg","hgidf","adfgedjgcdgiadajj","ijebjcbic","ciefheifgbeicdgibj","dgahi","fhjbgbb","hffejjdae","jacgigg","bahigaghgddabiagdij","gfeabiehidfcfcfffgea","gcca","gjjhhcejf","hfcbeacdfbdeeajgji","jghjcigggjiafaieg","ccdfbdbeef","iacd","dgfbhfbcbbgj","hcedhff","acbhggebigbcifibdjdc","dijadjjagjcgadfgabcj","jabadhi","dfagbfcbabbcciif","cfdebjhggbjhafhc","be","jieidigcehibbjhhedcc","diifieegbhbb","ddiaiiieiccd","bfca","bbjcdgeecdhigii","idjeice","jaagfbjgdjd","gjfffchggbide","ab","ddjcgdihdegfea","chdacahjheca","ihbcjeci","ei","ihggjiacddjcfej","jgjdgd","ceeeeb","eddhcj","afbffebghffhcbh","ajahbdbj","cdfeeffhida","jabeebj","jehheci","ahj","hhccigjeaaahbhei","gjhgijdb","achfdjhjdfa","ihadicdiehbfiib","gghf","ecghj","fcccfibhcdeidhdacedj","ebjdfadejcefcbafjbc","ifbcjghiafieadgj","igcahjccggagifdagci","gfgjhejggeebaicjhed","djdcca","gedddfjgcg","gjhcihgcjaigg","bci","bbajhdbegfff","efhdieahidccjbcfdg","bgaffaaffaahhiae","jdf","cacijjegcchbefjgegej","hceiacffdacegfadgdha","afcjfabgcfhcee","bgffafaii","bjcediebcfafjj","gbbdjcbhagbihgicdece","jgf","jcccigaiccb","ci","hfgbaagdcbc","eeddjcebbceechigbc","ai","ficjadcjcecdceaj","abibehhaghgdibbfdgf","bjhdbfiadbhhijha","ghfeiibagfafgag","idbcbhgggbfadbca","ddjf","aaedgijeacgigjcb","gfffcggdeagc","aigcejdddcjjcijhg","jidhf","ccjfiacjga","cfbgehdiijefghdi","cjhggijefc","ghefchcghdi","ggdgcg","cfcgcg","gejcg","hda","iiahbacjgcjeche","hggcdedcbaaa","edhffjjciefgaggjh","bdijbjecahccj","cghjf","heghfhbbcieefeihea","ecegbdhdiccfafjb","fefe","bjag","beiachiddeejjebaffc","abbeijcae","fibfgibgejge","hgiaeeabbjicbgcjacgh","dfehgedhibjegihg","cei","dbifdigijbhffcb","jdifecjeaech","ageaced","gjdgjijahd","afagejhighhjc","jgdedeeddifh","chgejdbgdfh","jcaiaacjfbe","gbbhehg","cgabjdf","idabcffjeca","hcigiiighaagfibcdee","gicjfefghjhgjbej","aiicbaibbhgij","gfjjgahcdhcfjgjh","dajjjcgjbjjhhjgede","gbihffaehafijb","jddiccefhiiaag","icbjgbjcddh","jheahdigdhba","egiagdbgcchceiigj","gdfjcj","jj","hejjgjdjafh","cbbahdiacf","jbdgggagfbhaea","hbghcjbg","bifbcdjhcjdgab","jgcfcdcgjf","gcechagbjjgig","ajfhcbg","fgdhbicahciibggi","gbgdgee","biebhj","gcbccegffdae","djihcai","ibb","acbdahhcac","hicggfibahcjjddbd","abcbbihcfijh","icfhhhejf","ahcajdabi","haifac","fhaabcebgcfgjhi","bjhegacjid","hi","ebbeifgfjbecgigbfbj","chjj","eihid","abagicda","cjdhdjcegifge","gdfebb","eehifdhcbfcgjcf","dfgihajihcfgggfgj","dfj","gcgjaejffacedeefadj","bbihahhd","cacfagiehijbfhh","jahdhbjgghjhbbcdc","bdaci","agbhjiddjibbbhi","iaahfjahijgehedehga","hba","hcaede","acebdibb","cidjeej","fjfaagbdhj","jgiijidfdhccdgaf","hebdh","hc","dgc","eihfdgfcfegjh","cifafgchef","dcjjaejbbhcg","ed","dchbadiijcgdgfhc","iachcahh","bbfdcbgebjdcgjdecjc","ieaahbbghbhcceiiih","ehcefbdjhaa","gfcebeaag","aagaciebjc","ddcj","ihiiffcjihjf","jg","iadefabbbi","abeecfbggefadj","hcegihihffefjfd","gg","adcjig","jcecbjgdabgf","hidiehjcfi","bagfgeidddaeg","idcfajfhbecdiffddjgi","jehejjiffejc","dffbicgbcg","jeechjjeicdhjhgbfbc","ihegffffddibgjaihb","giaji","ibffjff","aehigjjihjcjaaecaa","cfbbfhdiedfca","ffjgcfhbdgjjfibhcgbg","jcjeacdhfaejgjh","dehijfcc","iab","jfedijhadd","ddacabdggffeafhf","haefgjcghjb","ciiijbjcjggafffcbdh","gbejgbca","ejbcdbgdiij","cghgigjccgihdaadad","baibfhajibbgai","djigeegfhgjdbii","behgiggfbggagbjjead","hbafajbcegfagjfie","bjgadiehieaabjechad","hhahiefdddagii","fgai","gbghejhicfhgbfdd","igejcfiehdbedib","jhbcbheeghche","fahbjf","bhddiac","hbhgahbchia","bcgiajghhadjbi","fcecjebeeed","jffhfeebaehj","bdfgadjhibhdfe","aihaddcag","gadjh","hjfgbcjefchei","aeaeiiggdecjci","jdacdhacdf","fjibahfad","ghfhhjbi","jdadabecgjgdd","fdhjhcjafdddfbfddd","eebfecj","caejfacaj","ifjafd","ibjijg","difgbcbagd","bhdccjagda","hdaagjciddhidahaj","jciaaifajdbdigjahi","giiaed","hchg","jchigeafchcjihbhgfdh","cefibahdbdhdcdehhach","ecgd","iecfiagbehcbfieb","bfjbejaijcbdacdgebb","ghhedhgfgidbcghfbii","cgej","ijaibfjdh","jifid","ahaijbcahihaggfjb","cggjeeffjihiiegdgj","ececf","fdja","hgiajfjccahbf","edhhadhjcjf","aga","gibcgibbeiaadji","jfgbdccaceghed","dei","icgfdedd","iijegfhabaiaejfg","fbaj","jchcaeaegjefbbgdcj","hhjfdahegacbagcdehf","ibjd","jgbcajgbeeeee","gaheddaade","biheih","bichfdeiggebhdbeiii","giedafeadagehfbchg","ibbjaehhgccjbajg","hejfgfg","fcfadhbchbbafjicfia","ajegfdc","hffdecgdij","fgec","gcjdcgaibhfae","fahdcbfje","dbabdijahcfh","hhhjc","hjcfgjcjihfjac","cdhgaiffedf","ehjaeighajde","ficafaejah","fbeca","afecbj","jcd","accc","jibdbgaiiddbha","jahcbjhh","ehbfcjdhgbaabecfch","jjej","fbaccjcicjfg","gicjcdb","fafiedg","eggbiffacjabce","gjihijfaccg","ddjhgaacfdfaeiec","ddgbcbgh","bjheac","jfjjjcdiia","jcahdiadggahigeb","fhbdheeb","bbeeaiejcijceb","fg","dijd","jcbifefjafdbcecidf","igjdff","bii","jhadci","jfgafeb","jifdjafbhcahhgbdeaaf","ceefe","hjeiebejegdcebig","igcaah","efecjciecjfdfaj","iecchica","ghccagabfcb","begjcd","bjgbffajjfhebjjfijad","bcfcbfdabgcbhjj","bif","ajaheccibiiefcjbge","dgf","jbda","ieebjjhfddd","bhabdhjagihidc","hhhcbjebajgcj","dggjdafgb","jeddiddec","jaac","igichgciaiaejae","eej","adib","ghih","bacgdcagdgbg","adibdjaijcdaeiehbihj","hedjedijdiiihc","ihhd","cccahffddabbfge","fdebcb","gfbejgce","eahgedeeijdeebdh","ddhjahccdebicijacbab","gaiddj","dacfjdjhcjbdbbehaa","dcecgda","cajiaj","bjdideadicfhceheb","cabdjdgfcaeedjgef","cefaaagacdachb","cdeefbaifdhjijb","iehdejdeeejb","ggedij","gchacfdgcaje","jhjcibgjaijeha","diecfiaghagcha","daebehehfccgjcbhh","gdfbgag","cd","gddeffieffaefhijd","hcf","gihj","gicaehjec","gegfegiegdj","ijeihj","degje","gjigeiaa","cjhecbedhjbadbcbbbic","eciacehfadje","eebajeicfacgecddffce","ehgj","dhbccefceh","djedfbbfjbaje","abdbeaf","dehg","ig","caadabchdgibf","ad","ebhbjfhjfdhahddfgg","abcajbih","iceaffifhjgcfb","ffgaibdbhaaaeid","fbchgeihhahc","iaieajgab","jfijfjgbagjajhebc","gfhgaefjeaiiecghhagc","jhiaii","cgid","jgfgabagdjhfic","bcfibaeaaejbeghahdi","jaiihgeehbdceb","acidcfdh","cb","hhgdigdg","edfbdd","efdgegdeaeebjji","ccee","cbiadgbhahdifahc","ehdfbj","ejdcceiijiijf","efdjhi","ebgefdgfebidf","aaddehhaa","dgi","ehfbg","cicdecehhigjej","febcieagic","feffd","iiigddfegfggdafg","jch","fc","diddgccdhbeiaibdfb","hbbfecfdaih","fdegfh","aecjc","fgbebchgegfjahbbh","dhigah","ccdbeeabdif","aagg","didedhbcgbgjdbijfi","bihfbcbi","fjbiiabcaiciebfeeije","haefhdjbjafjdce","decgcfecbficieaija","bfgbia","hjgaidedej","daecbjhhghehbgagg","jic","caaih","ccbahijhdebdagcd","idcia","ebiafdbaagdfceaeh","icai","ddiddhaecdhbegiae","ggeggjefb","bieef","dbhiajdg","dijiicdcaecfahaghifh","hffej","bjicafedhie","bafaifaecdg","jeggaib","idefjigbhgggbehechdc","baaejhajhecfgh","bcbbbbcfiahihdigjh","bjgibahac","hhfgfchjdhd","idhigfhicbjdaahd","hbaccjb","hci","bfcfabgieahge","fejjgjehcfg","fdbcjfcdddcbgg","fj","ieefdchjddbjied","cgbcef","bjiaefaeacdeedidec","cjjjjheffeedi","eacbihacdghejb","hibfjbchjifhjehf","bhj","ddhigieieihc","ahdcdfjbbciijegbieh","hjifdabfcghefcagacdj","cdgejiia","efbbgdhce","fbcid","jc","ajggijeiehefihjfjcb","hfhbbcehbf","gdfejbf","dbbgigbgiigjaddbe","bbf","cfegjag","igcdiaefdcigeefb","adcea","ifbiffjhjbdb","ghba","bdfedag","gjhjbadcgh","djdcd","efbhdjhbgicfhg","jicggbdcjag","gdd","gfibdbdhja","fddeabcf","ifcffchfafigd","fieaj","dhac","jehieab","eiea","jaiiddehfecgbacjh","bjhdjcggcajcbjde","beeeeidcccfgheda","ajgehbggjcabjb","ie","ibaadgbddjaigedgj","jedf","difdjgd","faciicicciig","chafeahhi","iafhbdjjhgajcf","geh","dcgacbhdhddghd","afefahjbhigijaidhfa","cbdijeeaaag","ec","bbb","gafgabhbhejfib","iaihfebdjch","ifdbcjg","jaddcae","he","ac","gjajcgddaja","hee","bcce","abfjg","hchbeb","egeajedhh","gcbdchec","ggjdihjiibgafja","bhaeagf","bfajgcdcgahe","iceiidhjgjaaibeceg","eigefc" };
	//vector<vector<int>> res = A.palindromePairs(words);
	//for (int i = 0; i < res.size(); ++i)
	//	cout << res[i][0] << " " << res[i][1] << endl;
	//cout << endl << endl;
	//res = A.palindromePairs(words1);
	//for (int i = 0; i < res.size(); ++i)
	//	cout << res[i][0] << " " << res[i][1] << endl;
	return 0;
}