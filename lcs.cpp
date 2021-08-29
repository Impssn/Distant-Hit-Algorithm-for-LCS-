#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str1,str2,str3,ans,ans2;  // str1,str2 for 2 strings, str3 for exchange of strings if needed, ans for final lcs 
	int n,i,j,l1,l2,max=0;  // n=>least string's length, l1=>str1's length, l2=>str2's length, i,j are i=>row , j=>column, max=>maximum row or column
	bool ij;  // bool variable used to represent which is greater weather row(r) or column(c) if(r>c): then ij=0 if(c>r): then ij=1
	cout<<"\nEnter String 1: ";
	getline(cin,str1);
	cout<<"\nEnter String 2: ";
	getline(cin,str2);
	l1=str1.size();
	l2=str2.size();
	bool res[l1],res2[l2];  // Boolean array has 1 if the letter of that index is present in LCS else 0
	memset(res,0,sizeof(res));  // initialize Boolean array res and res2 to be 0's in all entries
        memset(res2,0,sizeof(res2));
	for(i=0;i<str1.size();i++)  // to traverse str1
	{
		for(j=0;j<str2.size();j++)   // to traverse str2
		{
			if(str1[i]==str2[j])
			{
				if(max==0)  //if first letters are equal we assign it's index to LCS
				{
					res[i]=1;
					i>=j?max=i,ij=0:max=j,ij=1;  // maximum(row,column) assigned to max
					break;
				}
			    if(max<i && ij==0)  //if 2 elmts are equal and resulting row greater than that of previous LCS elmt's row we assign it's index to LCS
				{
					res[i]=1;
					i>=j?max=i,ij=0:max=j,ij=1;   // maximum(row,column) assigned to max
					break;
				}
				if(max<j && ij==1)  //if 2 elmts are equal and resulting column greater than that of previous LCS elmt's column we assign it's index to LCS
				{
					res[i]=1;
					i>=j?max=i,ij=0:max=j,ij=1;   // maximum(row,column) assigned to max
					break;
				}
			}
		}
	}
	for(i=0;i<sizeof(res);i++)   // Assign the str1 to ans by checking if it's present in LCS 
	{
		if(res[i]==1)
		{
			ans+=str1[i];
		}
	}
    str3=str1;     //SWAP the strings 
    str1=str2;
    str2=str3;
    max=0;  // Re-initialize max to 0
	for(i=0;i<str1.size();i++)  // to traverse str1
    {
	    for(j=0;j<str2.size();j++)   // to traverse str2
	    {
		    if(str1[i]==str2[j])
		    {
			    if(max==0)    //if first letters are equal we assign it's index to LCS
			    {
					res2[i]=1;
				    i>=j?max=i,ij=0:max=j,ij=1;   // maximum(row,column) assigned to max
					break;
				}
				if(max<i && ij==0)     //if 2 elmts are equal and resulting row greater than that of previous LCS elmt's row we assign it's index to LCS
				{
				    res2[i]=1;
					i>=j?max=i,ij=0:max=j,ij=1;   // maximum(row,column) assigned to max
					break;
				}
				if(max<j && ij==1)    //if 2 elmts are equal and resulting column greater than that of previous LCS elmt's column we assign it's index to LCS
				{
					res2[i]=1;
					i>=j?max=i,ij=0:max=j,ij=1;   // maximum(row,column) assigned to max
					break;
			    }
			}
	   	}
    }
	for(i=0;i<sizeof(res2);i++)   // Assign the str1 to ans2 by checking if it's present in LCS 
	{
		if(res2[i]==1)
		{
			ans2+=str1[i];
		}
	}
	ans.size()>ans2.size()?ans=ans:ans=ans2;  // The Largest String is assigned as the LCS (ans)
	cout<<"\n Longest Common Subsequence (LCS) : "<<ans;  // view the LCS 
	cout<<"\n Length of LCS : "<<ans.size();  // view length of LCS
	return 0;
}
