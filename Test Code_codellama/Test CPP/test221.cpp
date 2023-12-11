using UnityEngine;
using System.Collections.Generic;

public class BloomPrePassBGLight
{
    private static List<BloomPrePassBGLight> _bloomBGLightList = new List<BloomPrePassBGLight>();

    public static List<BloomPrePassBGLight> get_bloomBGLightList()
    {
        return _bloomBGLightList;
    }

    public static void set_bloomBGLightList(List<BloomPrePassBGLight> bloomBGLightList)
    {
        _bloomBGLightList = bloomBGLightList;
    }

    public Color get_color()
    {
        return _color;
    }

    public void set_color(Color color)
    {
        _color = color;
    }

    private Color _color;
}
