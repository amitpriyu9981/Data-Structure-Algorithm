#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;


int main(){

   unordered_map<string,int> ourmap;

   // insert
   pair<string,int> p("Piyush",100);
   ourmap.insert(p);

   ourmap["Riya"]=200;

   // find functioon
   cout<<ourmap["piyush"]<<endl;
   cout<<ourmap.at("Riya")<<endl;

//    cout<<ourmap.at("Kajal")<<endl;     // here we get error, but incase of the square baracket we get 0
   // size function
   cout<<"size "<<ourmap.size()<<endl;
   cout<<ourmap["Kajal-singh"]<<endl;


   // count function
   if(ourmap.count("Kajal-singh")>0){
    cout<<"Kajal-singh is present"<<endl;
   }
   cout<<"size "<<ourmap.size()<<endl;
   

   // erease function
   ourmap.erase("Kajak-singh");
   cout<<"size "<<ourmap.size()<<endl;

}