import { useState } from 'react'
import './App.css'

function App() {
      const [itemName, setItemName] = useState("")
      const [quantity,setQuantity]=useState("");
      const [instructions, setInstruction]=useState("");

      const order={
        'itemName':itemName,
        'quantity':quantity,
        'instruction':instructions
      }
      const handleSubmit =async (e)=>{
                e.preventDefault();
                 await fetch('http://localhost:3000/order', {
                  method:'POST',
                  headers:{
                    'Content-Type': 'application/json'
                  },  
                  body:JSON.stringify(order)
                })        
      }

  return (
   <>
      <div className='heading'>
         <h1> Meghnas Biryani</h1>
      </div>
      <div className="container">
      <form className="form" onSubmit={handleSubmit}>
           <div className='inputs'>
           <label htmlFor="itemName">Item Name:</label>
           <input type="text" id='itemName' placeholder='Enter Item Name'  value={itemName} onChange={(e)=>{
              setItemName(e.target.value);
           }} />
           </div>
           <div className='inputs'>
           <label htmlFor="quantity">Quantity:</label>
           <input type="number" id='quantity' placeholder='0' value={quantity} onChange={(e)=>{
             setQuantity( e.target.value);
           }}/>
           </div>
           <div className='inputs'>
           <label htmlFor="special">Special Instructions:</label>
           <input type="text" id='special' placeholder='Add instructions' value={instructions} onChange={(e)=>{
             setInstruction(e.target.value)
           }}/>
           </div>

           <button type='submit'>Place Order</button>
      </form>
      </div>
   </>
  )
}

export default App

