export CUDA_VISIBLE_DEVICES=1
torchrun --rdzv_backend=c10d --rdzv_endpoint=localhost:0 --nnodes=1 --nproc_per_node 1 example_instructions.py --ckpt_dir CodeLlama-7b-Instruct --tokenizer_path CodeLlama-7b-Instruct/tokenizer.model --max_seq_len 20000 --max_batch_size 1
