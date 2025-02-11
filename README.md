# PortalRemake-DeferredRenderer

Github repo: https://github.com/MendelDebrabandere/PortalRemake-DeferredRenderer

This project was made during the Graphics Programming 2 cours at DAE: https://www.digitalartsandentertainment.be/page/48/Graphics+programming+2

The two main projects in this solution are the Portal Exam and the Deferred Renderer.
You can change what project is being run in the OverlordProject/MainGame.cpp file. It is decided based on what you have as #define.

![image](https://github.com/MendelDebrabandere/PortalRemake-DeferredRenderer/assets/95921047/05c35eb9-c54c-48ee-985d-fdd515402f78)



## Portal Remake
This is a remake from the Portal game from Valve. I only recreated the portal game mechanic and made a small level to demonstrate the mechanic. \
I really enjoyed working on this, from rendering to physics and maths.

![Portal](https://github.com/MendelDebrabandere/PortalRemake-DeferredRenderer/assets/95921047/1eeb85a8-d071-4914-918c-15ff0ee189e0)

## Deferred Renderer
This is an exploration of the deferred rendering pipeline where we first render all the data in a buffer and then afterwards we add lighting to construct the image. Compared to normal forward rendering,
deffered rendering allows for much more efficient calculation of lighting if there are a lot of lights in the scene. It also allows volumetric lighting.

![Portal](https://github.com/MendelDebrabandere/PortalRemake-DeferredRenderer/assets/95921047/c19667c1-9df3-4325-93e8-b10e34a1f821)
