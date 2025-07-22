#include "TextFileReader.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <iterator>

TextFileReader::TextFileReader(const std::string& infile)
  : file_ { infile }
  , fileContents_ { "" }
{
  fileContents_ = ReadFileContents();
}

std::string TextFileReader::GetFileContents() const
{
  return fileContents_;
}

std::string TextFileReader::ReadFileContents()
{
  std::fstream inputFile;
  std::cout << "Attempting to open file: " << file_ << std::endl;

  inputFile.open(file_);
  if(!inputFile.is_open())
  {
    std::cerr << "Failed to load file: " << file_ << std::endl;
    return "";
  }

  std::string contents { std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>() };

  inputFile.close();

  return contents;
}
