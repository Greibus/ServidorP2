import java.util.*;
import java.util.Map.Entry;
 

 
public class HuffmanDecoder {
    // input is an array of frequencies, indexed by character code
    
	public static HashMap<Character, String> CodeList = new HashMap();
	public static String codedString = "";
	
	
	public static HuffmanTree buildTree(int[] charFreqs) {
        
    	PriorityQueue<HuffmanTree> trees = new PriorityQueue<HuffmanTree>();
        
        // initially, we have a forest of leaves
        // one for each non-empty character
        for (int i = 0; i < charFreqs.length; i++)
            if (charFreqs[i] > 0)
                trees.offer(new HuffmanLeaf(charFreqs[i], (char)i));
 
        assert trees.size() > 0;
        
        // loop until there is only one tree left
        while (trees.size() > 1) {
            // two trees with least frequency
            HuffmanTree a = trees.poll();
            HuffmanTree b = trees.poll();
 
            // put into new node and re-insert into queue
            trees.offer(new HuffmanNode(a, b));
        }
        return trees.poll();
    }
 
    public static void printCodes(HuffmanTree tree, StringBuffer prefix) {
        assert tree != null;
        if (tree instanceof HuffmanLeaf) {
            HuffmanLeaf leaf = (HuffmanLeaf)tree;
 
            
            
            
            codedString+= prefix.toString();
            
            CodeList.put(leaf.value, prefix.toString());
            // print out character, frequency, and code for this leaf (which is just the prefix)
            System.out.println(leaf.value + "\t" + leaf.frequency + "\t" + prefix);
 
        } else if (tree instanceof HuffmanNode) {
            HuffmanNode node = (HuffmanNode)tree;
 
            // traverse left
            prefix.append('0');
            printCodes(node.left, prefix);
            prefix.deleteCharAt(prefix.length()-1);
 
            // traverse right
            prefix.append('1');
            printCodes(node.right, prefix);
            prefix.deleteCharAt(prefix.length()-1);
        }
    }
    
    
    
    
    public static String Decode(String toDecode)
    {
    	char[] codedArray = toDecode.toCharArray();
    	
    	String output = "";
    	String tempStr = "";
    	
    	if(!CodeList.isEmpty()) {
    		
    		for(int i = 0; i < codedArray.length; i++){
    			
    			tempStr += codedArray[i];
    			
    			System.out.println("tempStr: " + tempStr);
    			
    			for (Entry<Character, String> entry : CodeList.entrySet())
    			{
    			
    				
    			    if(tempStr.equals(entry.getValue()))
    			    {
    			    	
    			    	output += entry.getKey().toString();
    			    	tempStr = "";
    			    }
    			
    			    //System.out.println("output: " + output);
    			}
    			
    		}
    		return output;
    		
    	}else
    		return null;
    	
    }
    
    
    
    
    
    
    
    
    
    
    
 
    
        
}