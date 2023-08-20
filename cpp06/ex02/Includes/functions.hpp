#pragma once
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "Base.hpp"
#include <time.h>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "UI.hpp"

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif