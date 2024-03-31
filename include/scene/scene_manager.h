#pragma once

extern Scene *menu_scene;
extern Scene *game_scene;
extern Scene *gameover_scene;

class SceneManager
{
public:
    enum class SceneType
    {
        Menu,
        Game,
        GameOver,
    };

public:
    SceneManager() = default;
    ~SceneManager() = default;

    void set_current_scene(Scene *scene)
    {
        current_Scene = scene;
        current_Scene->on_enter();
    }

    void switch_scene(SceneType type)
    {
        current_Scene->on_exit();
        switch (type)
        {
        case SceneType::Menu:
            current_Scene = menu_scene;
            break;
        case SceneType::Game:
            current_Scene = game_scene;
            break;
        case SceneType::GameOver:
            current_Scene = gameover_scene;
            break;
        default:
            break;
        }
        current_Scene->on_enter();
    }

    void on_update(int delta_time)
    {
        current_Scene->on_update(delta_time);
    }

    void on_draw()
    {
        current_Scene->on_draw();
    }

    void on_input(const ExMessage &msg)
    {
        current_Scene->on_input(msg);
        current_Scene->on_enter();
    }

    SceneType get_current_scene_type() const
    {
        if (current_Scene == menu_scene)
            return SceneType::Menu;
        else if (current_Scene == game_scene)
            return SceneType::Game;
        else if (current_Scene == gameover_scene)
            return SceneType::GameOver;
        else
            return SceneType::Menu;
    }

private:
    Scene *current_Scene = nullptr;
};