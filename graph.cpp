#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<cstring>
#include<vector>
using namespace std;

int main(int argc, char* argv[])
{
	string line;
	string edgesList[14];
	ifstream myfile(argv[1]);
	int i=0;
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			//cout<<line<<endl;
			edgesList[i]=line;
			i++;
		}
	}
	int s,d;
	int vertices=stoi(edgesList[0]);
	int edges=stoi(edgesList[1]);
	int adjacencyMatrix[vertices][vertices];
	
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			adjacencyMatrix[i][j]=0;
		}
	}

	for(int i=2;i<14;i++)
	{
		s=(int)edgesList[i][0]-48;
		d=(int)edgesList[i][2]-48;
		adjacencyMatrix[s][d]=1;
		adjacencyMatrix[d][s]=1;
	}

	cout<<endl;
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			cout<<adjacencyMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
	int bclique[120][3];
	
	for(int i=0;i<120;i++)
	{
		bclique[i][0]=-1;
		bclique[i][1]=-1;
		bclique[i][2]=-1;
	}

	int m=0;
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			if(j!=i)
			{
				for(int k=0;k<vertices;k++)
				{
					if((k!=i) && (k!=j))
					{
						if((adjacencyMatrix[i][j]==1) && (adjacencyMatrix[j][i]==1)
							&& (adjacencyMatrix[j][k]==1) && (adjacencyMatrix[k][j]==1)
							&& (adjacencyMatrix[k][i]==1) && (adjacencyMatrix[i][k]==1))
						{
							bclique[m][0]=i;
							bclique[m][1]=j;
							bclique[m][2]=k;
							m++;				
							//cout<<i<<" "<<j<<" "<<k<<endl;
						}
					}
				}
			}
		}
	}

	int uniqueBC[15][3];
	for(int i=0;i<15;i++)
		{
			uniqueBC[i][0]=-1;
			uniqueBC[i][1]=-1;
			uniqueBC[i][2]=-1;
		}
	int ind=0;	
	for(int i=0;i<120;i++)
	{
		//cout<<bclique[i][0]<<" "<<bclique[i][1]<<" "<<bclique[i][2]<<endl;
	}
	int dec=-2;
	for(int i=0;i<120;i++)
	{
		if(bclique[i][0]!=-1)
		{
			for(int j=0;j<120;j++)
			{
				if(j!=i)
				{
					if(((bclique[i][0]==bclique[j][0])||(bclique[i][0]==bclique[j][1])||(bclique[i][0]==bclique[j][2])) && ((bclique[i][1]==bclique[j][0])||(bclique[i][1]==bclique[j][1])||(bclique[i][1]==bclique[j][2])) && ((bclique[i][2]==bclique[j][0])||(bclique[i][2]==bclique[j][1])||(bclique[i][2]==bclique[j][2])))
					{
						bclique[j][0]=dec;
						bclique[j][1]=dec;
						bclique[j][2]=dec;
						dec--;
					}
				}
			}
		}
	}

	for(int i=0;i<120;i++)
	{
		if(bclique[i][0]>=0)
		{
			uniqueBC[ind][0]=bclique[i][0];
			uniqueBC[ind][1]=bclique[i][1];
			uniqueBC[ind][2]=bclique[i][2];
			ind++;
		}
		//cout<<bclique[i][0]<<" "<<bclique[i][1]<<" "<<bclique[i][2]<<endl;	
	}

	for(int i=0;i<15;i++)
		cout<<uniqueBC[i][0]<<" "<<uniqueBC[i][1]<<" "<<uniqueBC[i][2]<<endl;
	
	int max=3;
	int arr[vertices];
	for(int i=0;i<vertices;i++)
		arr[i]=-1;
	int count=0;


	int ver[15][vertices];
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			ver[i][j]=-1;
		}
	}
	int y=0;
	for(int i=0;i<15;i++)
	{
		y=0;
		for(int j=0;j<vertices;j++)
		{
			if((j!=uniqueBC[i][0]) && (j!=uniqueBC[i][1]) && (j!=uniqueBC[i][2]))
			{
				if((adjacencyMatrix[j][uniqueBC[i][0]]==1) && (adjacencyMatrix[j][uniqueBC[i][1]]==1) && (adjacencyMatrix[j][uniqueBC[i][2]]==1))
				{
					ver[i][y]=j;
					y++;
				}
			}
		}
	}
	
	
	return 0;
}
