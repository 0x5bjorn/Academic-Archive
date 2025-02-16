#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "AbstractFigure.h"

std::shared_ptr<AbstractFigure> createFigure(const std::string& cmd);

#endif