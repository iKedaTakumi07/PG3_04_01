#pragma once

enum SCENE {
    title,
    stage,
    clear,
};

class IScene {
protected:
    static int sceneNo;

public:
    virtual ~IScene();

    virtual void Initialize() = 0;
    virtual void Update(char* keys, char* preKeys) = 0;
    virtual void Draw() = 0;

    int GetSceneNo() { return sceneNo; }
};
