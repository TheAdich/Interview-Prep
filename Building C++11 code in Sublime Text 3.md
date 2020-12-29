Go on this link : https://codeconnect.wordpress.com/2015/10/11/building-c11-code-in-sublime-text-3/
and follow the steps.

Infinite Loop Safe : https://codeforces.com/blog/entry/65048

Run these commands
brew install bash
brew install coreutils


Make a new Build System 

Copy paste below code after *** and before ***

***********************

{
 "cmd":["bash", "-c", "g++ -std=c++14 -Wall '${file}' -o '${file_path}/${file_base_name}' && gtimeout 0.5s '${file_path}/${file_base_name}'"],
 "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
 "working_dir": "${file_path}",
 "selector": "source.c, source.c++",
 "variants":
 [
   {
     "name": "Run",
     "cmd":["bash", "-c", "g++ -std=c++14 '${file}' -o '${file_path}/${file_base_name}' && gtimeout 0.5s '${file_path}/${file_base_name}' <input.txt >output.txt"]
   }
 ]
}

***********************

After all this try running this Infinite Monster. Don't worry you've got the powers to get it into control

***********************

#include <bits/stdc++.h>   
using namespace std;   

int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
   
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);   
    #endif   
    
    while (true) {   
        cout << "Hello World\n";   
    }   
        
}   

***********************

