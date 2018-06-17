import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.StringReader;
import java.io.StringWriter;
import java.util.*;
import java.util.Map.Entry;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

import org.w3c.dom.Attr;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
 
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
            //print out character, frequency, and code for this leaf (which is just the prefix)
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
    			
    			//System.out.println("tempStr: " + tempStr);
    			
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
    
    
    
    
	public String Encode(String toEncode) {
		
		CodeList.clear();
		
		System.out.println("String to encode: " + toEncode);
		
		// we will assume that all our characters will have
        // code less than 256, for simplicity
        int[] charFreqs = new int[256];
        
        
        
        
        // read each character and record the frequencies
        for (char c : toEncode.toCharArray()) {
            charFreqs[c]++;
            
        }
        
        HuffmanTree tree = buildTree(charFreqs);
        
        // print out results
        //System.out.println("SYMBOL\tWEIGHT\tHUFFMAN CODE");
        
        
        
        printCodes(tree, new StringBuffer());
        
        
        
        String codedString = "";
        
        for (char c : toEncode.toCharArray()) {
            
        	for (Entry<Character, String> entry : CodeList.entrySet())
            {
                if(entry.getKey() == c) {
                	codedString += entry.getValue();
                }
            }
            
        }
        
        return codedString;
        
	}
    
    
    
	public void xmlToCodes(String xmlString)
	{
		
		CodeList.clear();
		
		DocumentBuilder db = null;
	
		Document document = null;
		
		try {
			
			db = DocumentBuilderFactory.newInstance().newDocumentBuilder();
			
			document = db.parse( new InputSource( new StringReader( xmlString ) ) );
			
			
		
		
		} catch (SAXException | IOException e) {
		
			e.printStackTrace();
		} catch (ParserConfigurationException e1) {
			
			e1.printStackTrace();
		}
		
		Node mainNode = document.getFirstChild();
		
		NodeList nodeList = mainNode.getChildNodes();
	    for (int i = 0; i < nodeList.getLength(); i++) {
	        Node node = nodeList.item(i);
	        if (node.getNodeType() == Node.ELEMENT_NODE) {
	            
	        	String character = "";
	        	String code = "";
	        	
	        	
	        	character += node.getNodeName();
	        	code += node.getTextContent().toString();
	        	
	        	
	        	
	        	
	            //System.out.println(node.getNodeName() + ", code: " + node.getTextContent().toString());
	            CodeList.put(character.charAt(0), code);
	            
	        }
	    }
		
	    
	    for (Entry<Character, String> entry : CodeList.entrySet())
		{
		
			System.out.println("char: " + entry.getKey() + ", code: " + entry.getValue());
		
		    
		}
		
		
	}
    
    
	public String codesToXml()
	{
		 
		
		DocumentBuilderFactory docFactory = DocumentBuilderFactory.newInstance();
		DocumentBuilder docBuilder = null;
		try {
			docBuilder = docFactory.newDocumentBuilder();
		} catch (ParserConfigurationException e) {
			
			e.printStackTrace();
		}

		// root element
		Document document = docBuilder.newDocument();
		
		Element rootElement = document.createElement("message");
		document.appendChild(rootElement);
		
		
		// for each element in CodeList
		for (Entry<Character, String> entry : CodeList.entrySet())
		{
			
			
			Element charEle = document.createElement("character");
			
			rootElement.appendChild(charEle);
			
			Element character = document.createElement("key");
			character.appendChild(document.createTextNode(entry.getKey().toString()));
			
			Element code = document.createElement("code");
			code.appendChild(document.createTextNode(entry.getValue()));
			
			charEle.appendChild(character);
			charEle.appendChild(code);
	
		    
		}
		
		try
	    {
	       DOMSource domSource = new DOMSource(document);
	       StringWriter writer = new StringWriter();
	       StreamResult result = new StreamResult(writer);
	       TransformerFactory tf = TransformerFactory.newInstance();
	       Transformer transformer = tf.newTransformer();
	       transformer.transform(domSource, result);
	       return writer.toString();
	    }
	    catch(TransformerException ex)
	    {
	       ex.printStackTrace();
	       return null;
	    }
		
		
	}
    
        
}