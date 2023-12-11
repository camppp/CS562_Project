import java.util.*;
import java.util.stream.Collectors;

public class ResourceProcessDefinitionUtils {

    public static Map<Integer, Set<Integer>> getResourceProcessDefinitionMap(List<Map<String, Object>> list) {
        Map<Integer, Set<Integer>> resourceProcessDefinitionMap = new HashMap<>();

        list.stream()
               .flatMap(map -> map.entrySet().stream())
               .forEach(entry -> {
                    String processDefinitionId = entry.getKey();
                    List<Integer> resourceIds = (List<Integer>) entry.getValue();

                    resourceIds.forEach(resourceId -> {
                        resourceProcessDefinitionMap.putIfAbsent(resourceId, new HashSet<>());
                        resourceProcessDefinitionMap.get(resourceId).add(Integer.valueOf(processDefinitionId));
                    });
                });

        return resourceProcessDefinitionMap;
    }

    public static void main(String[] args) {
        List<Map<String, Object>> input = new ArrayList<>();
        Map<String, Object> map1 = new HashMap<>();
        map1.put("process1", Arrays.asList(1, 2, 3));
        map1.put("process2", Arrays.asList(2, 3, 4));
        input.add(map1);
        Map<String, Object> map2 = new HashMap<>();
        map2.put("process3", Arrays.asList(3, 4, 5));
        map2.put("process4", Arrays.asList(4, 5, 6));
        input.add(map2);

        Map<Integer, Set<Integer>> result = getResourceProcessDefinitionMap(input);
        System.out.println(result);
    }
}