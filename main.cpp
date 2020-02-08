#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<vector>

std::vector<std::string> split(const std::string& i_str, const std::string& i_delim)
{
	std:: vector<std::string> result;

    size_t found = i_str.find(i_delim);
    size_t startIndex = 0;

    while(found != std::string::npos)
    {
	    std::string temp(i_str.begin()+startIndex, i_str.begin()+found);
        result.push_back(temp);
        startIndex = found + i_delim.size();
        found = i_str.find(i_delim, startIndex);
    }
    if(startIndex != i_str.size())
        result.push_back(std::string(i_str.begin()+startIndex, i_str.end()));
    return result;      
}

int main(int argc,char** argv)
{

redi::ipstream proc("termux-speech-to-text", redi::pstreams::pstdout | redi::pstreams::pstderr);
  std::string line;
  // read child's stdout
  while (std::getline(proc.out(), line))
    std::cout << "stdout: " << line << '\n';
if(argc != 2)
{
	std::cout<<"Enter a valid statement";
	return 0;
}

std::string str(argv[1], strlen(argv[1]));
const std::string search ="what is ";
str.erase(0,search.length());
std::vector<std::string> ops = split(str," ");
std::vector<std::string>::iterator it;
it=ops.begin();
int opd1=std::stoi(*it);
it+=2;
int opd2=std::stoi(*it);
it--;
int ans;
	if(it->compare("plus")==0)
{
		ans = opd1+opd2;
		std::string message=std::string(("termux-tts-speak -s MUSIC \"the sum of the numbers is ")+std::to_string(ans)).c_str()+std::string("\"");
system(message.c_str());
}
	
return 0;
}
