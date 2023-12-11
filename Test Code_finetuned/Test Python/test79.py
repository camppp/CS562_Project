def custom_check(predicate):
    async def predicate_wrapper(ctx):
        if ctx.author.id!= Config.QT_ID:
            raise CanNotVerifyQt
        return await predicate(ctx)
    return commands.check(predicate_wrapper)