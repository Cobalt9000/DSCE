import streamlit as st
import pickle
import pandas as pd

# Load the model
model_path = 'model.pkl'
with open(model_path, 'rb') as f:
    random_forest = pickle.load(f)

# Define the categories and custom encoder
categories = ['No Failure', 'Heat Dissipation Failure', 'Power Failure', 'Overstrain Failure', 'Tool Wear Failure', 'Random Failures']
custom_encoder = {i: cat for i, cat in enumerate(categories)}

# Title of the web app
st.title("Machine Predictive Maintenance Classification")

# Input fields for user data
col1, col2 = st.columns(2)

with col1:
    selected_type = st.selectbox('Select a Type', ['Low', 'Medium', 'High'])
    type_mapping = {'Low': 0, 'Medium': 1, 'High': 2}
    selected_type = type_mapping[selected_type]

with col2:
    air_temperature = st.text_input('Air temperature [K]')

with col1:
    process_temperature = st.text_input('Process temperature [K]')

with col2:
    rotational_speed = st.text_input('Rotational speed [rpm]')

with col1:
    torque = st.text_input('Torque [Nm]')

with col2:
    tool_wear = st.text_input('Tool wear [min]')

# Prediction logic
failure_pred = ''

if st.button('Predict Failure'):
    try:
        # Convert inputs to float
        air_temperature = float(air_temperature)
        process_temperature = float(process_temperature)
        rotational_speed = float(rotational_speed)
        torque = float(torque)
        tool_wear = float(tool_wear)

        # Create a DataFrame for the prediction input
        input_data = pd.DataFrame([[selected_type, air_temperature, 
                                    process_temperature, rotational_speed,
                                    torque, tool_wear]], 
                                  columns=['Type', 'Air temperature [K]', 'Process temperature [K]', 'Rotational speed [rpm]', 'Torque [Nm]', 'Tool wear [min]'])

        # Make a prediction
        prediction = random_forest.predict(input_data)

        # Interpret prediction
        failure_pred = custom_encoder[prediction[0]]
            
    except ValueError:
        st.error("Please enter valid numeric values for all input fields.")
    except Exception as e:
        st.error(f"An error occurred: {str(e)}")

# Display prediction result
st.success(failure_pred)
