sharp
using System;
using System.Text;

public class UniqueIdGenerator
{
    public string GenerateRequestId()
    {
        const string prefix = "REQ-";
        const string suffix = "-2022";
        const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        Random random = new Random();
        StringBuilder requestIdBuilder = new StringBuilder(prefix);

        for (int i = 0; i < 6; i++)
        {
            requestIdBuilder.Append(chars[random.Next(chars.Length)]);
        }

        requestIdBuilder.Append(suffix);
        return requestIdBuilder.ToString();
    }
}
