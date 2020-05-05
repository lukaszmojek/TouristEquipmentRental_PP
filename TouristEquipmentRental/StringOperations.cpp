#include "StringOperations.h"

StringOperations::StringOperations()
{

}

vector<string> StringOperations::Split(const string& s, char separator)
{
   vector<std::string> tokens;
   string token;
   istringstream tokenStream(s);

   while (getline(tokenStream, token, separator))
   {
      tokens.push_back(token);
   }

   return tokens;
}
