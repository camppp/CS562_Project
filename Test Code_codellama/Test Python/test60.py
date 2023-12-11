import dacbench.envs.modea
import dacbench.envs.sgd
import dacbench.envs.onell_env
import dacbench.envs.modcma
import dacbench.envs.toysgd

def create_environment(env_name):
    if env_name == "modea":
        return dacbench.envs.modea.ModeaEnv()
    elif env_name == "sgd":
        return dacbench.envs.sgd.SGDEnv()
    elif env_name == "onell":
        return dacbench.envs.onell_env.OneLLEnv()
    elif env_name == "modcma":
        return dacbench.envs.modcma.ModCMAEnv()
    elif env_name == "toysgd":
        return dacbench.envs.toysgd.ToySGDEnv()
   