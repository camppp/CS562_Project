Sr25519Keypair CryptoStoreImpl::generateSr25519Keypair(KeyTypeId key_type, const Sr25519Seed &seed) {
  // Generate the keypair using the sr_suite_
  Sr25519Keypair keypair = sr_suite_.generateKeypair(seed);

  // Get the cache associated with the provided key_type
  auto cache = getCache(key_type);

  // Insert the generated keypair into the cache
  cache->insert(keypair);

  return keypair;
}
