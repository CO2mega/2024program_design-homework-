#include <iostream>
#include <cstdlib> 
int main() {
   
    std::string repoPath = "/path/to/your/repo";
    std::string gitConfigUser = "git config user.name \"YourUsername\"";
    std::string gitConfigEmail = "git config user.email \"your.email@example.com\""; 
    std::string cdCommand = "cd " + repoPath;
    system(cdCommand.c_str());
    system(gitConfigUser.c_str());
    system(gitConfigEmail.c_str()); 
    system("git add .");
    system("git commit -m \"Automatic commit from C++ program\"");
    system("git push origin master");

    return 0;
}
