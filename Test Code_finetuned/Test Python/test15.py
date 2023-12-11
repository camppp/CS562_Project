def generate_tmux_commands(session, base_cmd, num_workers, remotes, logdir):
    cmds_map = [new_tmux_cmd(session, "ps", base_cmd + ["--job-name", "ps"])]
    for i in range(num_workers):
        cmds_map.append(new_tmux_cmd(session, "w-%d" % i, base_cmd + ["--job-name", "worker", "--task", str(i), "--remotes", remotes[i]]))
    cmds_map.append(new_tmux_cmd(session, "tb", ["tensorboard --logdir {} --port 12345".format(logdir)]))
    cmds_map.append(new_tmux_cmd(session, "htop", ["htop"]))
    return cmds_map