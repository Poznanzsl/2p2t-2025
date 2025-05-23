import { StyleSheet } from "react-native";
import { Colors } from "../../assets/cssVariables";

export default StyleSheet.create({
  container: { 
    flex: 1,
    backgroundColor:Colors.white,
    alignItems: 'center',
    justifyContent: 'center',
    },

    button:{
      width:'20%',
      height:'5%',
      backgroundColor: Colors.darkGreen,
      display:'flex',
      justifyContent:'center',
      alignItems:'center',
    }
});