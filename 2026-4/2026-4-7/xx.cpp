#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a = "1234*";
	int b = stoi(a);
	cout << b;
	return 0;
}
int main()
{
	string a ;
	string b ;
	int c = 0;
	string date ;
	cin >> a;
	cin >> b;
	cin >> c;
	date += a + b;
	int i = 0;
	for (i = 0; i < c; i++)
	{
		int number = date[i] - '0';
		int number2 = date[i + 1] - '0';
		date += to_string(number * number2);
		cout << date[i]<<' ';
	}
	return 0;
}
void swa(int* a, int* b)
{
	int ret = *a;
	*a = *b;
	*b = ret;
}
void CreatSmallPile(int* root, int parent,int End)
{
	int child = parent * 2 + 1;
	while (child < End)
	{
		if (child+1<=End&&root[child] > root[child + 1])
		{
			child += 1;
		}
		if (root[parent] > root[child])
		{
			swa(&root[parent], &root[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
int FindNumber(string a)
{
	if (a.find("root") != std::string::npos)
	{
		return 1;
	}
	if (a.find("siblings") != std::string::npos)
	{
		return 2;
	}
	if (a.find("parent") != std::string::npos)
	{
		return 3;
	}
	if (a.find("child") != std::string::npos)
	{
		return 4;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int amount = 0;
	int proposition = 0;
	cin >> amount;
	cin >> proposition;
	int pile[5];
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &pile[i]);
	}
	getchar();
	int root = (sizeof(pile)/4) - 1;
	for (i = (root - 1) / 2; i >= 0; i--)
	{
		CreatSmallPile(pile,i,root+1);
	}
	for (i = 0; i < proposition; i++)
	{
		string s1;
		getline(cin, s1);
		int a = FindNumber(s1);
		int date = stoi(s1.substr(0, 4));
		int j = 4;
		int date1 = 0;
		for (j = 4; j < s1.length(); j++)
		{
			if (s1[j] >= '0' && s1[j] <= '9')
			{
				date1 = stoi(s1.substr(j));
				break;
			}
		}
		switch (a)
		{
			case 1:
			if (pile[0] != date)
			{
				cout << "F\n";
			}
			else
			{
				cout << "T\n";
			}
			break;
			case 2:
				for (j = 0; j < amount; j++)
				{
					if (pile[j] == date1 || pile[j] == date)
					{
						if((j-1)/2==j/2)
						{
							cout << "T\n";
							break;
						}
						else
						{
							cout << "F\n";
							break;
						}
					}
				}
				break;
			case 3:
				for (j = 0; j < amount; j++)
				{
					if (pile[j] == date1)
					{
						if (pile[(j - 1) / 2] == date)
						{
							cout << "T\n";
							break;
						}
						else
						{
							cout << "F\n";
							break;
						}
					}
				}
				break;
			case 4:
				for (j = 0; j < amount; j++)
				{
					if (pile[j] == date)
					{
						if (pile[(j - 1) / 2] == date1)
						{
							cout << "T\n";
							break;
						}
						else
						{
							cout << "F\n";
							break;
						}
					}
				}
				break;
			case 0:
				break;
		}
	}
	return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        int a1 = 0.0f;
        int b1 = 0.0f;
        cin >> a1;
        cin >> b1;
        a1 = ((a1 - 100) * 0.9) * 2;
        if (a1>b1?a1-b1:b1-a1 < a1 * 0.1)
        {
            cout << "You are wan mei!\n";
        }
        else if (b1 - a1 > a1 * 0.1)
        {
            cout << "You are tai pang le!\n";
        }
        else
        {
            cout << "You are tai shou le!\n";
        }
    }
    return 0;
}
using namespace std;
#include <iostream>
using namespace std;
int main()
{
    int add[] = { 0,0,0,0,0,0,0,1,2,3,4,5,6,7,8 };
    int n = 0;
    int m = 0;
    cin >> n;
    cin >> m;
    int i = 0;
    char arr[4];
    for (i = 0; i < m; i++)
    {
        scanf(" %s", arr);
        char* p1 = arr;
        int j = 0;
        int root = 0;
        for (j = 0; j < n; j++)
        {
            if (p1[j] == 'y' && (root * 2) + 1 < sizeof(add) / 4)
            {
                root = (root * 2) + 1;
            }
            else if (p1[j] == 'n' && (root * 2) + 2 < sizeof(add) / 4)
            {
                root = (root * 2) + 2;
            }
            else
            {
                break;
            }
        }
        printf("%d\n", add[root]);
    }
    return 0;
}