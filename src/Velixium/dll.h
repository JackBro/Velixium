#pragma once

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4049)

#include "../BlackBone/Config.h"
#include "../BlackBone/LocalHook/LocalHook.hpp"
#include "../BlackBone/Process/Process.h"
#include "../BlackBone/PE/PEImage.h"
#include "../BlackBone/Misc/Utils.h"
#include "../BlackBone/Misc/DynImport.h"
#include "../BlackBone/Process/RPC/RemoteFunction.hpp"
#include "../BlackBone/Patterns/PatternSearch.h"

#include <iostream>
#include <fstream>

using namespace blackbone;
using namespace std;

extern Process engine;

#include "Logger\Logger.h"
#include "Proxy\Proxy.h"
#include "DirectX\DirectX.h"