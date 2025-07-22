#pragma once

#include <string>
class TextFileReader {
public:
  TextFileReader(const std::string &infile);
  std::string GetFileContents() const;

private:
  std::string ReadFileContents();

private:
  std::string         file_;
  std::string fileContents_;
};
