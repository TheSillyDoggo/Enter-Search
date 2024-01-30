#include <Geode/Geode.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/modify/FLAlertLayer.hpp>

using namespace geode::prelude;

class $modify (FLAlertLayer)
{
	bool init(FLAlertLayerProtocol* p0, char const* p1, gd::string p2, char const* p3, char const* p4, float p5, bool p6, float p7, float p8)
	{
		if (!FLAlertLayer::init(p0, p1, p2, p3, p4, p5, p6, p7, p8))
			return false;

		this->setID("FLAlertLayer");

		return true;
	}
};

class $modify (LevelSearchLayer)
{	
	bool init(int idk)
	{
		if (!LevelSearchLayer::init(idk))
			return false;

		this->setID("LevelSearchLayer"); // node id's does the exact same thing and this is the same id. but node id's isn't on mac so here's a workaround

		return true;
	}
};

class $modify (CCKeyboardDispatcher)
{
	bool dispatchKeyboardMSG(cocos2d::enumKeyCodes key, bool down, bool idk)
	{
		if (key == enumKeyCodes::KEY_Enter && down)
		{
			if (CCDirector::get()->getRunningScene()->getChildByID("LevelSearchLayer"))
			{
				log::info("search");

				as<LevelSearchLayer*>(CCDirector::get()->getRunningScene()->getChildByID("LevelSearchLayer"))->onSearch(nullptr);
				
				return true;
			}
			else if (CCDirector::get()->getRunningScene()->getChildByID("FLAlertLayer"))
			{
				as<FLAlertLayer*>(CCDirector::get()->getRunningScene()->getChildByID("FLAlertLayer"))->onBtn2(nullptr);
			}
		}
		else
		{
			return CCKeyboardDispatcher::dispatchKeyboardMSG(key, down, idk);
		}

		return true;
	}
};