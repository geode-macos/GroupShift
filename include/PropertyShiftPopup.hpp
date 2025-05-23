#include "ShiftPopup.hpp"

class PropertyShiftPopup : public ShiftPopup {
public:
    struct ObjectCollection : public CCObject {
		std::vector<EffectGameObject*> data;
		ObjectCollection(std::vector<EffectGameObject*> objs) {
			data = objs;
			this->autorelease();
		}
	};
	int minValue;
	int maxValue;
	std::function<std::vector<float>(EffectGameObject*)> getProperty;
    std::function<void(EffectGameObject*, std::vector<float>)> setProperty;
	void onButtonPress(CCObject* obj) override;
	bool setup(FLAlertLayer*) override;
	static PropertyShiftPopup* create(
		std::vector<EffectGameObject*> objects,
		FLAlertLayer* popup,
		std::function<std::vector<float>(EffectGameObject*)> getProperty,
		std::function<void(EffectGameObject*, std::vector<float>)> setProperty,
		int minValue, int maxValue);
	static PropertyShiftPopup* create(
		std::vector<EffectGameObject*> objects,
		FLAlertLayer* popup,
		std::function<std::vector<float>(EffectGameObject*)> getProperty,
		std::function<void(EffectGameObject*, std::vector<float>)> setProperty
	) { return create(objects, popup, getProperty, setProperty, 1, 9999); }
};