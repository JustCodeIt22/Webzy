#pragma once

// including c++ libs
#include <unordered_map>
#include <memory>

// including own libs
#include "HTMLComponents/Component.hpp"
#include "HTMLComponents/Text.hpp"
#include "HTMLComponents/Image.hpp"
#include "HTMLComponents/Button.hpp"

static std::unordered_map<std::string, std::shared_ptr<Component>> HTML_COMPONENTS = 
{
    {"Text", std::make_shared<Text>()}, 
    {"Image", std::make_shared<Image>()},
    {"Button", std::make_shared<Button>()},
};

