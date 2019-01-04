//
// Created by engin on 18.05.2018.
//

#ifndef LIMONENGINE_ANIMATIONCUSTOM_H
#define LIMONENGINE_ANIMATIONCUSTOM_H


#include "AnimationNode.h"
#include "../../Transformation.h"
#include "AnimationInterface.h"
#include <memory>

class AnimationCustom : public AnimationInterface {
    friend class AnimationLoader;
    friend struct AnimationSequenceInterface;

    float ticksPerSecond;
    float duration;

    std::shared_ptr<AnimationNode> animationNode;

    std::string name;

    /*this private constructor is meant for deserialize only*/
    AnimationCustom() = default;

public:
    AnimationCustom(const std::string &animationName, std::shared_ptr<AnimationNode> animationNode, int duration)
            : ticksPerSecond(60), duration(duration), name(animationName) {
            this->animationNode = animationNode;
    }

    AnimationCustom(const AnimationCustom &otherAnimation) {
        this->ticksPerSecond = otherAnimation.ticksPerSecond;
        this->duration = otherAnimation.duration;
        this->name = otherAnimation.name;
        this->animationNode = std::make_shared<AnimationNode>(*(otherAnimation.animationNode));//default copy constructor used
    }

    bool calculateTransform(const std::string& nodeName __attribute((unused)), float time __attribute((unused)), Transformation& transformation) const;

    float getTicksPerSecond() const {
        return ticksPerSecond;
    }

    float getDuration() const {
        return duration;
    }

    const std::string& getName() const {
        return name;
    }

    bool serializeAnimation(const std::string &path) const;
};


#endif //LIMONENGINE_ANIMATIONCUSTOM_H
