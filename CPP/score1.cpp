// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// int main()
// {
//     locale system("");
//     locale::global(system);

//     wcin.imbue(system);

//     wstring data;
//     getline(wcin,data);

//     wcout.imbue(system);
//     wcout << data << L" length=" << data.length() << endl;

//     locale utfFile("zh_CN.UTF-8");
//     wofstream file("my_utf_file.txt");
//     file.imbue(utfFile);

//     file << data;
//     file << endl;

//     file.close();

//     return 0;
// }
// #include <iostream>
// #include <sstream>
// #include <locale>
 
// int main()
// {
//     std::istringstream iss;
//     iss.imbue(std::locale("zh_CN.UTF8"));
 
//     std::cout << "Current locale: " << iss.getloc().name() << '\n';
//     std::cout << "Current locale: " << std::cout.getloc().name() << '\n';

 
//     iss.imbue(std::locale());
//     std::cout << "Global locale : " << iss.getloc().name() << '\n';
// }

#include <stdio.h>
#include <locale.h>
#include <wchar.h>

#include <string>
#include <iostream>

using namespace std;


const char* psa = "A汉字ABC";
const wchar_t* psw = L"W汉字ABC";

int main(int argc, char* argv[])
{
    // init.
    //ios::sync_with_stdio(false);    // Linux gcc.
    // locale::global(locale(""));
    // //setlocale(LC_CTYPE, "");    // MinGW gcc.
    // wcout.imbue(locale(""));

    // C++
    cout << psa;  cout.clear();     cout<<endl;
    wcout << psw;  wcout.clear();     wcout<<endl;

    // C
    printf("\nC:\n");
    printf("\t%s\n", psa);
    printf("\t%ls\n", psw);

    return 0;
}