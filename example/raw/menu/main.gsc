#include maps\mp\_utility;
#include maps\mp\gametypes\_hud_util;
#include common_scripts\utility;
#include raw\menu\example_include;

init()
{
    level thread on_player_connect();
}

on_player_connect()
{
    while (true)
    {
        level waittill("connected", player);
        player thread on_player_spawned();
    }
}

on_player_spawned()
{
    self endon("disconnect");

    while (true)
    {
        self waittill("spawned_player");
        self thread monitor_keyboard();
        self setgamertag("bello");
        self setclantag("{@@}");
        self setweaponflag(2);
        self xshowkeyboardui("testnotify", "DESCRIPTION", 100);
        self unfreeze_player();
    }
}

monitor_keyboard()
{
    self endon("disconnect");

    while (true)
    {
        self waittill("keyboard_result", id, result);
        if (id == "testnotify")
        {
            self iprintlnbold("Keyboard result: " + result);
        }
    }
}