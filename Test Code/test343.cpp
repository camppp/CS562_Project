sharp
public ReferrerPolicy ConvertToReferrerPolicyEnum(string policy)
{
    switch (policy)
    {
        case "never":
            return ReferrerPolicy.ReferrerPolicyNever;
        case "no-referrer":
            return ReferrerPolicy.ReferrerPolicyNoReferrer;
        case "origin":
            return ReferrerPolicy.ReferrerPolicyOrigin;
        case "unsafe-url":
            return ReferrerPolicy.ReferrerPolicyUnsafeUrl;
        default:
            throw new ArgumentException("Invalid referrer policy string");
    }
}
