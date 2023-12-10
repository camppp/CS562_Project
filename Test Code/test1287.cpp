javascript
function filterEventsByEventIds(events, eventIds) {
  const filterByEventId = (eventId) => (event) => event.id === eventId;
  return events.filter((event) => eventIds.includes(event.id));
}

// Test
const events = [
  { id: "001" },
  { id: "002" },
  { id: "003" },
  { id: "004" }
];
const eventIds = ["002", "003"];
console.log(filterEventsByEventIds(events, eventIds));
