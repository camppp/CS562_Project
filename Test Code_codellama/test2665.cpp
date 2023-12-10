def extractCommentBlock(comment: str) -> List[str]:
    lines = comment.splitlines()
    return [line.strip() for line in lines if line.startswith("*")]
