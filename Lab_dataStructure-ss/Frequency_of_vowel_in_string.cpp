#include<iostream>
using namespace std;

int main()
{
    string str;
    cout<<"Enter string : ";
    getline(cin,str);

    int freq_a=0,freq_e=0,freq_i=0,freq_o=0,freq_u=0;

    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='a'||str[i]=='A')
            freq_a++;
        else if(str[i]=='e'||str[i]=='E')
            freq_e++;
        else if(str[i]=='i'||str[i]=='I')
            freq_i++;
        else if(str[i]=='o'||str[i]=='O')
            freq_o++;
        else if(str[i]=='u'||str[i]=='U')
            freq_u++;
    }
    cout<<"Frequency of A/a :"<<freq_a<<endl;
    cout<<"Frequency of E/e :"<<freq_e<<endl;
    cout<<"Frequency of I/i :"<<freq_i<<endl;
    cout<<"Frequency of O/o :"<<freq_o<<endl;
    cout<<"Frequency of U/u :"<<freq_u<<endl;
}
