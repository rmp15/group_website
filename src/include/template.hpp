#pragma once

#include <string>
#include <vector>
#include <unordered_map>

struct Template
{
  std::string name;
  std::vector<std::string> args;

  std::vector<std::string> text;
  std::vector<std::string> argOrder;
};

typedef std::unordered_map<std::string, Template *> TemplateMap;

class TemplateManager
{
private:
  TemplateMap *tmap;
  void templateCreatorParser(std::string templateFile);
public:
  TemplateManager(std::string templateFile);
  // Read string from md like: {{template}}
  std::string templateReaderParser(std::string);
  std::string templateRenderer();
  std::unordered_map<std::string, std::string> *generateTemplateArgValueMap(std::vector<std::string> args);
};

void parseAndSaveTemplateContent(Template *temp, std::string templateContent);
