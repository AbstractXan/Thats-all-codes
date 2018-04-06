#include<bits/stdc++.h>
#include"Directory.h"
using namespace std;
void showmenu()
{
	cout<<"\n Choose an option:\n";
	cout<<"0. Exit\n1. Build from Directory.txt\n2. Check phone number(s) of a person\n3. Modify number of a person\n4. Delete number of a person\n5. Add number of a person\n6. Commit changes to directory\n";
	cout<<"-------------------------------------------\n";
}

main(int argc,char* argv[]){
	
	int option=1;
	//Check if directory has been updated nad not committed
	bool committed=false;
	Directory dir;
	dir.build();

	while(option!=0)
	{
		showmenu();
		cin>>option;
		string tempname,tempnumber;
		switch(option)
		{
			case 0:
				if(committed==false)
				{
					cout<<"\n Changes made haven't been committed. Do you want to quit(y/n)?\n";
					char temp;
					cin>>temp;
					if(temp=='y'||temp=='Y')	
						return 0;
					else
						break;
				}
				else
				{
					return 0;
				}
				break;
			case 1:
				if(committed==false)
				{
					cout<<"\n Changes made haven't been committed. Continue?\n";
					char temp;
					cin>>temp;
					if(temp=='y'||temp=='Y')
					{	
						Directory c;
						dir = c;
						dir.build();
						committed=true;
					}
					else
						break;
				}
				else
				{
					dir.build();
				}
				break;
				
			case 2:
				cout<<"\nEnter the name of person to MODIFY in Directory:\n";
				cin>>tempname;
				dir.check(tempname);
				break;
			case 3:
				cout<<"\nEnter the name of person to MODIFY in Directory:\n";
				cin>>tempname;
				dir.modify(tempname);
				committed=false;
				break;
			case 4:
				cout<<"\nEnter the name of person to DELETE from Directory:\n";
				cin>>tempname;
				dir.deletenum(tempname);
				committed=false;
				break;
			case 5:
				cout<<"\nEnter the name and number to add to Directory:\n";
				cin>>tempname>>tempnumber;
				dir.addnum(tempname,tempnumber);
				committed=false;
				break;
			case 6:
				dir.commit();
				committed=true;
				break;
			
			default:
				cout<<"\n Invalid input!\n";
				
		}
		
	}

	return 0;
}
