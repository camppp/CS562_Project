def pred_output_location(message_in, message_out):
    # Get the agent's ID
    agent_id = FLAMEGPU.getID()

    # Calculate the square of the agent's ID using the helper function
    square = helper(agent_id)

    # Assign the offset value
    offset = 10

    # Update the message_out with the result of the computation and the offset value
    message_out.setVariableInt("result", square + offset)