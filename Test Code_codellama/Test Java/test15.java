public class VoteRecord {
    public String post_id;
    @Column(name="vote_item_index")
    public int vote_item_index = -1;

    public static void create(String paramString1, String paramString2, int paramInt) {
        VoteRecord localVoteRecord = new VoteRecord();
        localVoteRecord.account_id = paramString1;
        localVoteRecord.post_id = paramString2;
        localVoteRecord.vote_item_index = paramInt;

        // Additional logic for saving the vote record to the database or performing other operations
    }
}