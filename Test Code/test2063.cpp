Sr25519Keypair CryptoStoreImpl::generateSr25519Keypair(
    KeyTypeId key_type, const Sr25519Seed &seed) {
  // Generate keypair using the provided seed
  Sr25519Keypair kp = sr_suite_->generateKeypair(seed);
  
  // Retrieve the cache associated with the provided KeyTypeId
  Cache& keyTypeCache = getCache(sr_suite_, sr_caches_, key_type);
  
  // Insert the generated keypair into the cache
  keyTypeCache.insert(kp.public_key, kp.secret_key);
  
  // Return the generated keypair
  return kp;
}
