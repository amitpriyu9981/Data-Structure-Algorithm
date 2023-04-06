#include<iostream>
#include<string>

using namespace std;
// #include "trieclass.h"
// #include "trieclass2.h"
#include "Trie.h"


int main() {
	Trie t;
	t.insertWord("and");
	t.insertWord("are");
	t.insertWord("dot");

	cout << t.search("and") << endl;

	t.removeWord("and");
	cout << t.search("and") << endl;
}


// int main(){


    
//     int choices; cin>>choices;
//     trie t;

//     while(choices != -1){
//         string word; 
//         switch(choices){
//             case 1:  // for inserting the word 
//                cin>>word;
//                t.insertword(word);
//                break;
//             case 2:  // for searching the word the word 
//                cin>>word;
//                cout<<t.searchword(word)?"True":"False";
//                break;
//             default:
//                return 0;
//         }
//         cin>>choices;
//     }
//     return 0;
// }