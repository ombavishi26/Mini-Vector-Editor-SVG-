// #include <string>
namespace Default{
    constexpr const char* stroke = "black";
    constexpr float strokewidth = 1.0f;
    constexpr const char* fill = "none";

    namespace rect{
        constexpr float width = 10.0;
        constexpr float height = 10.0;
        constexpr float x = 0.0;
        constexpr float y = 0.0;
        constexpr float rx = 0.0;
        constexpr float ry = 0.0;
    }

    namespace circle{
        constexpr float r = 10.0;
        constexpr float cx = 0.0;
        constexpr float cy = 0.0;
    }
    
    namespace linr{
        constexpr float x1 = 0.0;
        constexpr float y1 = 0.0;
        constexpr float x2 = 10.0;
        constexpr float y2 = 10.0;
    }
}