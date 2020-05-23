# Minecraft 1.2.5 C++ Client
A project, where, using WebAssembly we attempt to write a Minecraft 1.2.5 client. Should (hopefully) eventually be fully featured, and be able to run on (most) low-end systems.

Note: As of now, it is required that a server be in offline mode for the C++ client to connect.

## Progression Goals
1. Impliment Client Core In C++ **(Starting)**

    Support all packets, main control loop. Essentially a full-fledged bot.

2. Port Core to WASM *(Future)*

    Use Emscripten to move core, make fully compatable

3. Impliment C++ Graphics Engine *(Future)*

    Any assistance would be helpful, currently looking for possibilities.

4. Port Project Entirely to WASM *(Far Future)*



5. Create system to easily make servers be able to connect *(Far, Far Future)*

    Current understanding is that Websockify would need to be running on server (or similar machine) to act as a proxy between client and target.

