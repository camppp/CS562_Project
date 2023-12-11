import subprocess

def generate_tmux_commands(session, base_cmd, num_workers, remotes, logdir):
    cmds_map = {
        "ps": new_tmux_cmd(session, "ps", base_cmd + ["--job-name", "ps"]),
        "w-{}".format(i): new_tmux_cmd(session, "w-{}".format(i), base_cmd + ["--job-name", "worker", "--task", str(i), "--remotes", remotes[i]]) for i in range(num_workers)
    }
    
    # Add TensorBoard command
    cmds_map["tb"] = new_tmux_cmd(session, "tb", ["tensorboard --logdir {} --port 12345".format(logdir)])
    
    # Add htop command
    cmds_map["htop"] = new_tmux_cmd(session, "htop", ["htop"])
    
    return cmds_map