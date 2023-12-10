sharp
using UnityEngine;
using System.Collections.Generic;

public class BloomPrePassBGLight
{
    private static List<BloomPrePassBGLight> _bloomBGLightList = new List<BloomPrePassBGLight>();

    public static List<BloomPrePassBGLight> get_bloomBGLightList()
    {
        return _bloomBGLightList;
    }

    private Color color;

    public Color get_color()
    {
        return color;
    }

    public void set_color(Color value)
    {
        color = value;
    }
}
