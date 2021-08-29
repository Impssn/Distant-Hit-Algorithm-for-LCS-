#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str1,str2,str3,ans,ans2;  // str1,str2 for 2 strings, str3 for exchange of strings if needed, ans for final lcs 
	int n,i,j,l1,l2,max=0;  // n=>least string's length, l1=>str1's length, l2=>str2's length, i,j are loop variables
	bool ij;
	cout<<"\nEnter String 1: ";
	getline(cin,str1);
	cout<<"\nEnter String 2: ";
	getline(cin,str2);
	l1=str1.size();
	l2=str2.size();
   /*	l1>l2?n=l1:n=l2;
	if(l1<l2)   // Always str1 is to be the string of greater size (SWAP if str1 size < str2 size)
	{
	   str3=str1;
	   str1=str2;
	   str2=str3;
	}*/
	bool res[l1],res2[l2];  // Boolean array has 1 if the letter of that index is present in LCS else 0
	memset(res,0,sizeof(res));  // initialize Boolean array res to be 0's in all entries
     memset(res2,0,sizeof(res2));
	for(i=0;i<str1.size();i++)  // to traverse str1
	{
		for(j=0;j<str2.size();j++)   // to traverse str2
		{
			if(str1[i]==str2[j])
			{
				if(max==0)
				{
						res[i]=1;
						i>=j?max=i,ij=0:max=j,ij=1;
						
						break;
				}
					if(ij==0)
				{
					if(max<i){
					
						res[i]=1;
						i>=j?max=i,ij=0:max=j,ij=1;
						
						break;}
				}
				if(ij==1)
				{
						if(max<j)
				{
						res[i]=1;
						i>=j?max=i,ij=0:max=j,ij=1;
						
						break;
				}
				}
			    // set res's entry to 1 if the letter on that index is present in LCS
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
	   str3=str1;
	   str1=str2;
	   str2=str3;
	   max=0;
	   	for(i=0;i<str1.size();i++)  // to traverse str1
	{
		for(j=0;j<str2.size();j++)   // to traverse str2
		{
			if(str1[i]==str2[j])
			{
				if(max==0)
				{
						res2[i]=1;
						i>=j?max=i,ij=0:max=j,ij=1;
						
						break;
				}
					if(ij==0)
				{
					if(max<i){
					
						res2[i]=1;
						i>=j?max=i,ij=0:max=j,ij=1;
						
						break;}
				}
				if(ij==1)
				{
						if(max<j)
				{
						res2[i]=1;
						i>=j?max=i,ij=0:max=j,ij=1;
						
						break;
				}
				}
			    // set res's entry to 1 if the letter on that index is present in LCS
			}
		}
	}
	for(i=0;i<sizeof(res2);i++)   // Assign the str1 to ans by checking if it's present in LCS 
	{
		if(res2[i]==1)
		{
			ans2+=str1[i];
		}
	}
	ans.size()>ans2.size()?ans=ans:ans=ans2;
	cout<<"\n Longest Common Subsequence (LCS) : "<<ans;  // view the LCS 
	cout<<"\n Length of LCS : "<<ans.size();  // view length of LCS
	return 0;
}
