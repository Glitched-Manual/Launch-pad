// string list filter

#include <iostream>
#include <string>
#include <vector>

int main()
{

std::string databasesList ="manual-img,glass-img";
std::string collect;

std::vector<std::string> filteredList;
for(int m = 0; m <= databasesList.length(); ++m)
{
    if(databasesList[m] != ',')
    {

//	std::cout << databasesList[m];
	
	collect += databasesList[m];
	
	if(m == databasesList.length() -1)
     {
         
         filteredList.push_back(collect);
         std::cout << "max reached" << std::endl;
         
         std::cout << collect << std::endl;
     }
     }
     
     
     else
     {
         std::cout << std::endl;
         filteredList.push_back(collect);
         collect = "";
         std::cout << "collect cleared" << std::endl;
     }
    
}


 //std::cout << std::endl << databasesList[databasesList.length() -1] << std::endl;
 

 int it = 0;
 
 for(auto a : filteredList)
 {
     std::cout <<it<<". "<< a << std::endl;
     it++;
 }

//std::cout <<filteredList[1]<< std::endl;

return 0;
}