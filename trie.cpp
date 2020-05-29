/* The program to search words in a file
change the getIndex() as u wish

Author : rohith

*/
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
#define lli long long int
#define mod 1000000007
#define MAX_ALP_SIZE 256
class trieNode
{
	public:
		trieNode *alp[MAX_ALP_SIZE];
		bool isEnd;
};
class trieFunc
{
	public:
		lli i=0;
		trieNode *createNode()
		{
			trieNode *newNode = new trieNode();
			for(i=0;i<MAX_ALP_SIZE;i++)
			{
				newNode->alp[i]=NULL;
			}
			newNode->isEnd=false;
			return newNode;
		}
		lli getIndex(char ch)//can be changed later
		{
			if(ch>=65 && ch<=90)
				return ch+32;
			else
				return ch-0;
		}
		trieNode *insert(trieNode *root,string str,trieNode *curNode,lli level)
		{
			if(level==str.length())
			{
				curNode->isEnd=true;
				return root;
			}
			lli index = this->getIndex(str[level]);
			if(curNode->alp[index] == NULL)
				curNode->alp[index] = new trieNode();
			curNode = curNode->alp[index];
			return this->insert(root,str,curNode,level+1);
		}
		bool search(trieNode *root,string str)
		{
			trieNode *curNode = root;
			for(lli i=0;i<str.length();i++)
			{
				lli index = this->getIndex(str[i]);
				if(curNode->alp[index] == NULL)
					return false;
				curNode = curNode->alp[index];
			}
			if(curNode->isEnd)
				return true;
			else
				return false;
		}
}trie;
int main()
{
	lli n,i;
	/*cout<<"Enter number of strings:";
	cin>>n;*/
	string line,str;
	trieNode *root = trie.createNode();
	
	//opening a file
	ifstream fin;
	fin.open("mbox.txt");
	while(fin)
	{
		getline(fin,line);
		stringstream ss(line);
		string word;
		while(ss>>word)
		{
			//cout<<word<<"\n";
			root = trie.insert(root,word,root,0);
		}
	}
	fin.close();
	/*
	cout<<"Enter strings to construct a trie\n";
	for(i=0;i<n;i++)
	{
		cin>>str;
		root = trie.insert(root,str,root,0);
	}*/
	cout<<"Enter a word to search:";
	cin>>str;
	if(trie.search(root,str))
		cout<<"Found\n";
	else
		cout<<"Not Found\n";
	return 0;
}
