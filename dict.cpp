
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int alphabets  =26;

struct Node{

    struct Node* children [alphabets]={};
    int occurences;
    bool flag;

};
void insert_trie(struct Node * trietree,char * word)
{
struct Node * current=trietree;// current node so that the address of root of the trie is not lost
while(*word!='\0'){

    if(current->children[*word-'a']==NULL)
    {
        current->children[*word-'a']= (struct Node *) calloc(1, sizeof(struct Node)); //If there is no path along,create space
    }
    current=current->children[*word-'a'];            //otherwise follow the existing path
  ++word;
}
current->flag=true;
}
struct Node* search_trie(struct Node* current,char* word){

while(*word!='\0')
    {
if(current->children[*word-'a']!=NULL)
{
    current=current->children[*word-'a'];
    ++word;
}
else
    break;
}
if(*word=='\0'){
    return current;
}
else
    return NULL;
// look for every character we are searching


}
void autocomplete(struct Node* trietree, vector <char> word,char* prefix){
    bool nochild=true;
if(trietree->flag==true && word.size()!=0){// if word.size() is not kept here , it is gonna print the prefix so keep this check
    // first print what is given as prefix
    cout<<prefix;// now after this print the things which follow in word
    for(int i=0;i<word.size();i++){
        cout<<word[i];
    }
    cout<<endl;

}
for(int i=0;i<alphabets;i++){
if(trietree->children[i]!=NULL){

    word.push_back(i+'a');
    autocomplete(trietree->children[i],word,prefix);
    word.pop_back();
}
}
word.pop_back();
}


int main()
{

 struct Node * trietree = new Node();
 char filename[100];
	ifstream infile;
	cin.getline(filename,100);
	infile.open(filename);
if(!infile.is_open()){
    cout<<"Some problem in opening the file!"<<endl;
	exit(EXIT_FAILURE);
}
char word[50];
infile>>word;
while(infile.good()){

	 insert_trie(trietree,word);
	infile>>word;
}

vector <char > ch;
cout<<"enter the word to be searched"<<endl;
cin>>word;
Node* temp=search_trie(trietree,word);
if(temp==NULL)
    cout<<"NO word with this prefix in dictionary "<<endl;
else
autocomplete(temp,ch,word);

    return 0;
}
