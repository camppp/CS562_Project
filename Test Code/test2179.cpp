javascript
function setBottomFaceTints(block, tint_west_bot, tint_east_bot) {
  block.lightingTint.west_bot[0] = tint_west_bot[0];
  block.lightingTint.west_bot[1] = tint_west_bot[1];
  block.lightingTint.west_bot[2] = tint_west_bot[2];
  
  block.lightingTint.east_bot[0] = tint_east_bot[0];
  block.lightingTint.east_bot[1] = tint_east_bot[1];
  block.lightingTint.east_bot[2] = tint_east_bot[2];
}
