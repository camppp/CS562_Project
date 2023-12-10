#include <valhalla/midgard/pointll.h>
#include <valhalla/sif/costconstants.h>
#include <valhalla/sif/edgelabel.h>
#include <valhalla/sif/pathlocation.h>
#include <valhalla/proto/api.pb.h>
#include <valhalla/proto/directions_options.pb.h>
#include <valhalla/proto/tripdirections.pb.h>
#include <valhalla/proto/trippath.pb.h>
#include <valhalla/proto/trip.pb.h>
#include <valhalla/proto/trace.pb.h>
#include <valhalla/proto/waypoint.pb.h>
#include <valhalla/sif/costconstants.h>
#include <valhalla/sif/edgelabel.h>
#include <valhalla/sif/pathlocation.h>
#include <valhalla/sif/edgestatus.h>
#include <valhalla/sif/edgestatus.h>
#include <valhalla/sif/edgestatus.h>
#include <valhalla/sif/edgestatus.h>
#include <valhalla/sif/edgestatus.h>
#include <valhalla/sif/edgestatus.h>
#include <valhalla/sif/edgestatus.h>
#include <valhalla/sif/edgestatus.h>
#include <valhalla/sif/edgestatus.h>
#include <valhalla/sif/edgestatus.h>
#include <valhalla/sif/edgestatus.h>
#include <valhalla/sif/edgestatus.h>
#include <valhalla/sif/edgestatus.h>
#include <valhalla/sif/edgestatus.h>

void PathLocation::toPBF(const PathLocation& location, valhalla::Location* pbf_location, const valhalla::baldr::GraphReader& reader) {
  // Convert the point to PBF format
  pbf_location->mutable_ll()->set_lng(location.latlng_.lng());
  pbf_location->mutable_ll()->set_lat(location.latlng_.lat());

  // Convert edges to PBF format
  for (const auto& edge : location.edges) {
    auto* path_edge = pbf_location->mutable_correlation()->add_edges();
    path_edge->set_id(edge.id);
    path_edge->set_percent_along(edge.percent_along);
    path_edge->mutable_ll()->set_lng(edge.ll.lng());
    path_edge->mutable_ll()->set_lat(edge.ll.lat());
    path_edge->set_distance(edge.distance);
  }

  // Convert filtered edges to PBF format
  for (const auto& filtered_edge : location.filtered_edges) {
    auto* filtered_path_edge = pbf_location->mutable_correlation()->add_filtered_edges();
    filtered_path_edge->set_id(filtered_edge.id);
    filtered_path_edge->set_percent_along(filtered_edge.percent_along);
    filtered_path_edge->mutable_ll()->set_lng(filtered_edge.ll.lng());
    filtered_path_edge->mutable_ll()->set_lat(filtered_edge.ll.lat());
    filtered_path_edge->set_distance(filtered_edge.distance);
  }
}
