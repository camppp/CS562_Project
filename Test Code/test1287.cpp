function filterEventsByEventIds(events, eventIds) {
  return events.filter(event => eventIds.includes(event.id));
}
